

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<errno.h>
#include<arpa/inet.h>
#include<signal.h>
#include<netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/in_systm.h>
#define BUFSIZE 1500     //���ͻ������ֵ
 
//�������ͱ���
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
 
char hello[]="hello this is  a ping test.";
 
char *hostname; //��ping������
int  datalen=56;//ICMP��ϢЯ�������ݳ���
char sendbuf[BUFSIZE];
char recvbuf[BUFSIZE];
int nsent;//���͵�ICMP��Ϣ���
int nrecv;
pid_t pid;//ping����Ľ���pid
struct timeval recvtime; //�յ�ICMPӦ���ʱ���
int sockfd; //���ͺͽ���ԭʼ�׽���
struct sockaddr_in dest;//��ping������ip
struct sockaddr_in from;//����pingӦ����Ϣ������ip
 
struct sigaction act_alarm;
struct sigaction act_int;
 
 
//���õ�ʱ����һ���ṹ�壬����ʱ���ã��ظ���ʱ����ʱֵ��Ϊ1��
struct itimerval val_alarm;
 
//����ԭ��
void alarm_handler(int);//SIGALRM�������
void int_handler(int);//SIGINT�������
void set_sighandler();//�����źŴ������
void send_ping();//����ping��Ϣ
void recv_reply();//����pingӦ��
u16 checksum(u8 *buf,int len);//����У���
int handle_pkt(int len);//ICMPӦ����Ϣ����
void get_statistics(int ,int);//ͳ��ping����ļ����
void bail(const char *);//���󱨸�
int main(int argc,char **argv)  //argc��ʾ���γ����������в�������Ŀ��argv��һ��ָ���ַ�������ָ�룬����ÿһ���ַ���Ӧһ������
{
    val_alarm.it_interval.tv_sec = 1;
    val_alarm .it_interval.tv_usec=0;
    val_alarm  .it_value.tv_sec=0;
    val_alarm  .it_value.tv_usec=1;
    struct hostent *host; //�ýṹ������include<netdb.h>
    int on =1;
    
    if(argc<2){      //�ж��Ƿ������˵�ַ
        printf("Usage: %s hostname\n",argv[0]);
        exit(1);
    }
    
    if((host=gethostbyname(argv[1]))==NULL)
    {    //gethostbyname()���ض�Ӧ�ڸ����������İ����������ֺ͵�ַ��Ϣ�Ľṹָ��,
        perror("can not understand the host name");   //��ⲻ������ĵ�ַ
        exit(1);
    }
    
    hostname=argv[1];//ȡ����ַ��
    
    memset(&dest,0,sizeof dest);  //��dest��ǰsizeof(dest)���ֽ��滻Ϊ0������s,�˴�Ϊ��ʼ��,������ڴ�����
    dest.sin_family=PF_INET;  //PF_INETΪIPV4��internetЭ�飬��<netinet/in.h>�У���ַ��
    dest.sin_port=ntohs(0);   //�˿ں�,ntohs()����һ���������ֽ�˳���������
    dest.sin_addr=*(struct in_addr *)host->h_addr_list[0];//host->h_addr_list[0]�ǵ�ַ��ָ��.����IP��ַ����ʼ��
    
    if((sockfd = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP))<0)
    { //PF_INEI�׽���Э���壬SOCK_RAW�׽������ͣ�IPPROTO_ICMPʹ��Э�飬����socket����������һ���ܹ���������ͨ�ŵ��׽��֡������ж��Ƿ񴴽��ɹ�
        perror("raw socket created error");
        exit(1);
    }
    
    setuid(getuid());//getuid()��������һ�����ó������ʵ�û�ID,setuid()������ͨ�û�������root�û��Ľ�ɫ����ֻ��root�ʺŲ������еĳ�������
    pid=getpid(); //getpid��������ȡ��Ŀǰ���̵Ľ���ʶ����
    printf("PID:%d\n",pid);
    set_sighandler();//���źŴ���
    printf("Ping %s(%s): %d bytes data in ICMP packets.\n",argv[1],inet_ntoa(dest.sin_addr),datalen);
    
    if((setitimer(ITIMER_REAL,&val_alarm,NULL))==-1) //��ʱ����
        bail("setitimer fails.");
    
    
    recv_reply();//����pingӦ��
    
    return 0;
}
//����ping��Ϣ
void send_ping()
{
    
    struct ip *ip;   //ipΪIPͷ���ṹ��
    struct icmp *icmp;   //icmpΪICMPͷ���ṹ��
    int len;
    int len1;
    icmp=(struct icmp *)(sendbuf);  //�ַ���ָ��
    icmp->icmp_type=ICMP_ECHO;//��ʼ��ICMP��Ϣ����type
    
    icmp->icmp_code=0;    //��ʼ����Ϣ����code
    icmp->icmp_id=pid;   //�ѽ��̱�ʶ���ʼ��icmp_id
    icmp->icmp_seq=nsent++;  //���͵�ICMP��Ϣ��Ÿ�ֵ��icmp���
    gettimeofday((struct timeval *)icmp->icmp_data,NULL); // ��ȡ��ǰʱ��
    memcpy(icmp->icmp_data+sizeof(timeval), hello, strlen(hello));
    len=8+sizeof(timeval)+strlen(hello);
    printf("%d\n",len);
    icmp->icmp_cksum=0;    //��ʼ��
    icmp->icmp_cksum=checksum((u8 *)icmp,len);  //����У���
    sendto(sockfd,sendbuf,len,0,(struct sockaddr *)&dest,sizeof (dest)); //��socket��������
}
//���ճ��򷢳���ping�����Ӧ��
void recv_reply()
{
    int n;
    socklen_t len;
    int errno;
    n=nrecv=0;
    
    while(nrecv<4)
    {
        if((n=recvfrom(sockfd,recvbuf,sizeof recvbuf,0,(struct sockaddr *)&from,&len))<0)
        { //��socket��������,�����ȷ���շ��ؽ��յ����ֽ�����ʧ�ܷ���0.
            if(errno==EINTR)  //EINTR��ʾ�ź��ж�
                continue;
            bail("recvfrom error");
        }
        
        gettimeofday(&recvtime,NULL);   //��¼�յ�Ӧ���ʱ��
        
        if(handle_pkt(n))    //���յ������ICMPӦ����Ϣ
            
            continue;
        nrecv++;
    }
    
    get_statistics(nsent,nrecv);     //ͳ��ping����ļ����
}
//����У���
u16 checksum(u8 *buf,int len)
{
    u32 sum=0;
    u16 *cbuf;
    
    cbuf=(u16 *)buf;
    
    while(len>1)
    {
        sum+=*cbuf++;
        len-=2;
    }
    
    if(len)
        sum+=*(u8 *)cbuf;
    
    sum=(sum>>16)+(sum & 0xffff);
    sum+=(sum>>16);
    
    return ~sum;
}
//ICMPӦ����Ϣ����
int handle_pkt(int len)
{
    struct ip *ip;
    struct icmp *icmp;
    
    int ip_hlen,icmplen;
    double rtt; // ����ʱ��
    struct timeval *sendtime;
    
    ip=(struct ip *)recvbuf;
    
    ip_hlen=ip->ip_hl<< 2;
    icmp=(struct icmp *)(recvbuf+ip_hlen);
    icmplen=len-ip_hlen;
    if(icmp->icmp_id!=pid)
        return -1;
    if(icmp->icmp_type!=ICMP_ECHOREPLY)
        return -1;
    
    sendtime=(struct timeval *)icmp->icmp_data; //����ʱ��
    
    if((recvtime.tv_usec-=sendtime->tv_usec)<0)
    {
        recvtime.tv_sec--;
        recvtime.tv_usec+=1000000;
    }
    recvtime.tv_sec-=sendtime->tv_sec;
    
    rtt=recvtime.tv_sec*1000.0+recvtime.tv_usec/1000.0;// ����ʱ��
    //��ӡ���
    printf("%d bytes from %s:icmp_seq=%u ttl=%d rtt=%.3f ms\n",
           icmplen, //icmp���ݳ���
           inet_ntoa(from.sin_addr),    //Ŀ��ip��ַ
           icmp->icmp_seq, //icmp�������к�
           ip->ip_ttl,  //����ʱ��
           rtt);    //����ʱ��
    
    return 0;
}
//�����źŴ������
void set_sighandler()
{
    act_alarm.sa_handler=alarm_handler;
    if(sigaction(SIGALRM,&act_alarm,NULL)==-1)  //sigaction()��������signumָ�����źű�������ø��źŵĴ�����������signumָ��Ҫ�����źŻ���Ե��źţ�&act���������õ��źŹ����壬NULL����֮ǰ���õ��źŴ���ṹ�塣�����ж϶��źŵĴ����Ƿ�ɹ���
        bail("SIGALRM handler setting fails.");
    
    act_int.sa_handler=int_handler;
    if(sigaction(SIGINT,&act_int,NULL)==-1)
        bail("SIGALRM handler setting fails.");
}
//ͳ��ping����ļ����
void get_statistics(int nsent,int nrecv)
{
    printf("--- %s ping statistics ---\n",inet_ntoa(dest.sin_addr)); //�������ַת���ɡ�.��������ַ�����ʽ��
    printf("%d packets transmitted, %d received, %0.0f%% ""packet loss\n",
           nsent,nrecv,1.0*(nsent-nrecv)/nsent*100);
}
//���󱨸�
void bail(const char * on_what)
{
    fputs(strerror(errno),stderr);  //:��ָ�����ļ�д��һ���ַ�������д���ַ���������Ƿ���\0�������ɹ�д��һ���ַ������ļ���λ��ָ����Զ����ƣ���������ֵΪ0�����򷵻�EOR(���ų�������ֵΪ-1)��
    fputs(":",stderr);
    fputs(on_what,stderr);
    fputc('\n',stderr); //��һ���ַ���һ������
    exit(1);
}
 
//SIGINT���ж��źţ��������
void int_handler(int sig)
{
    get_statistics(nsent,nrecv);    //ͳ��ping����ļ����
    close(sockfd);  //�ر������׽���
    exit(1);
}
//SIGALRM����ֹ���̣��������
void alarm_handler(int signo)
{
    send_ping();    //����ping��Ϣ
    
}

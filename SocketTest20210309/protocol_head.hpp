#define MAX_LEN 1024;
typedef struct _iphdr // ����IP��ͷ
{
    // #if defined(__LITTLE_ENDIAN_BITFIELD)
    // unsigned char h_len : 4; // 4λ�ײ�����
    // unsigned char ver : 4; // 4λIP�汾��
    // #elif defined(__BIG_ENDIAN_BITFIELD)
    // unsigned char ver : 4; // 4λIP�汾��
    // unsigned char h_len: 4; // 4λ�ײ�����
    // #endif
    unsigned char h_verlen: 4;
    unsigned char tos;
    unsigned short total_len;
    unsigned short ident;
    unsigned short frag_and_flags;
    unsigned char ttl;
    unsigned char proto;
    unsigned short checksum;
    unsigned int sourceIP;
    unsigned int destIP;
} IP_HEADER;

typedef struct psd_hdr  // ����TCPα��ͷ
{
    unsigned long saddr; // Դ��ַ
    unsigned long daddr; // Ŀ�ĵ�ַ
    char mbz;
    char ptcl; // Э������
    unsigned short tcpl;// TCP����
} PSD_HEADER;

typedef struct _tcphdr // ����TCP��ͷ
{
    unsigned short th_sport; // 16λԴ�˿�
    unsigned short th_dport; // 16λĿ�Ķ˿�
    unsigned int th_seq; // 32λ���к�
    unsigned int th_ack; // 32λȷ�Ϻ�
    unsigned char th_lenres; // 4λ�ײ�����/6λ������
    unsigned char th_flag; // 6λ��־λ
    // unsigned short tcp_res1: 4,
    // tcp_hlen: 4, tcp_fin: 1, tcp_syn: 1,
    // tcp_rst: 1, tcp_psh: 1, tcp_ack: 1,
    // tcp_urg: 1, tcp_res2: 2;
    unsigned short th_win; // 16λ���ڴ�С
    unsigned short th_sum; // 16λУ���
    unsigned short th_urp; // 16λ��������ƫ����
} TCP_HEADER;

typedef struct _udphdr // ����UDP��ͷ
{
    unsigned short uh_sport; // 16λԴ�˿�
    unsigned short uh_dport; // 16λĿ�Ķ˿�
    unsigned short uh_len; // 16λ����
    unsigned short uh_sum; // 16λУ���
} UDP_HEADER;

typedef struct _icmphdr // ����ICMP��ͷ(���ͻ������Ӧ)
{
    unsigned char i_type; // 8λ����
    unsigned char i_code; // 8Ϊ����
    unsigned short i_cksum; // 16λУ���
    unsigned short i_id; // ʶ���(һ���ý��̺���Ϊʶ���)
    unsigned short i_seq; // �������к�
    unsigned int timestamp; // ʱ���
} ICMP_HEADER;


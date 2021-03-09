#define MAX_LEN 1024;
typedef struct _iphdr // 定义IP报头
{
    // #if defined(__LITTLE_ENDIAN_BITFIELD)
    // unsigned char h_len : 4; // 4位首部长度
    // unsigned char ver : 4; // 4位IP版本号
    // #elif defined(__BIG_ENDIAN_BITFIELD)
    // unsigned char ver : 4; // 4位IP版本号
    // unsigned char h_len: 4; // 4位首部长度
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

typedef struct psd_hdr  // 定义TCP伪报头
{
    unsigned long saddr; // 源地址
    unsigned long daddr; // 目的地址
    char mbz;
    char ptcl; // 协议类型
    unsigned short tcpl;// TCP长度
} PSD_HEADER;

typedef struct _tcphdr // 定义TCP报头
{
    unsigned short th_sport; // 16位源端口
    unsigned short th_dport; // 16位目的端口
    unsigned int th_seq; // 32位序列号
    unsigned int th_ack; // 32位确认号
    unsigned char th_lenres; // 4位首部长度/6位保留字
    unsigned char th_flag; // 6位标志位
    // unsigned short tcp_res1: 4,
    // tcp_hlen: 4, tcp_fin: 1, tcp_syn: 1,
    // tcp_rst: 1, tcp_psh: 1, tcp_ack: 1,
    // tcp_urg: 1, tcp_res2: 2;
    unsigned short th_win; // 16位窗口大小
    unsigned short th_sum; // 16位校验和
    unsigned short th_urp; // 16位紧急数据偏移量
} TCP_HEADER;

typedef struct _udphdr // 定义UDP报头
{
    unsigned short uh_sport; // 16位源端口
    unsigned short uh_dport; // 16位目的端口
    unsigned short uh_len; // 16位长度
    unsigned short uh_sum; // 16位校验和
} UDP_HEADER;

typedef struct _icmphdr // 定义ICMP报头(回送或回送响应)
{
    unsigned char i_type; // 8位类型
    unsigned char i_code; // 8为代码
    unsigned short i_cksum; // 16位校验和
    unsigned short i_id; // 识别号(一般用进程号作为识别号)
    unsigned short i_seq; // 报文序列号
    unsigned int timestamp; // 时间戳
} ICMP_HEADER;


#ifndef __SERVER_H__
#define __SERVER_H__

//TODO:实现一个基础的epoll_server框架

class LogServer
{
public:
	LogServer();
	~LogServer();

private:
	static bool SetNoBlock(int fd);
    static bool Addfd(struct sockaddr_in* pAddr, map<int, CSocketClient*>* pMapBuffer, int epollfd, int fd);
    static bool Delfd(map<int, CSocketClient*>* pMapBuffer, int epollfd, int fd);
    static bool EpollELWork(stuThreadParam* pStu, int number);
    static void* ThreadEpollWork(void* param);

    // Config
    char m_strCfgIP[SIZE_CLIENT_IP_MAX];//server IP
    int m_nCfgPort;//server port
    int m_nCfgLimitNum;
    int m_nSizeTask;
    int m_nSizeThreadPoolMax;//max size of Pool
    int m_nSizeThreadPoolPre;

    // LogServer连接属性
    int m_ListenFd;
    struct sockaddr_in m_addr;
    int m_EpollFd;
    epoll_event m_events[RLIMIT_MAX];

     // 内存逻辑管理变量
    bool m_bThreadEpollWork;//判断是否开启了LogServer
    map<int, void*> m_mapBuffer;//用于收集登录的客户信息
    stuThreadParam m_parWork;
    CThreadPoolManager m_mgrThreadPool;             // 线程池管理

    struct rlimit m_rt;                             // 用以设置连接数量

    bool LoadConfig();//读入配置文件
    bool SetLimitMax();//设置最大连接数
    bool ShowSocketStatus();
    bool ThreadPollInit();//目前用不上
    bool MaskSignal();
    bool CreateSocket();
    bool CreateEpoll();
    bool BindSocket();
    bool ListenSocket();
	
public:
	bool Init();
	bool Run();
	bool Destory();
};

#endif
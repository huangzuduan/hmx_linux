Welcome to the HMX_LINUX wiki!
# HMX_LINUX
HMX_LINUX分步式服务器框架，主要分为网关、登录、世界、场景、数据服务器，适用于大中小型项目

版本更新记录：

1. 2017-04-28 移植了WIN版本的HMX-Server代码到Centos6.5平台下，可以正常编译与启动


后续
1、会继续维护该版本，原WIN版本将暂停维护
2、增加过程线程启动
3、完善功能

# 安装步骤
0. 本项目使用boost1.60,mysql5.6版本
1. 下载后，将去配置Makefile.in的boost,mysql等的头文件及库引下目录
2. 进入各个项目目录进行make编译
3. 配置service.xml配置文件的数据库帐号与密码
4. 依次启动WorldServerD,DBServerD,LoginServerD,GameServerD,GatewayServerD,ClientD

***

# 目录介绍
1. Bin/Debug/ 编译存放目录
2. Resource/ 配置及资源目录
3. Source/ 源代码文件
   1. Client/ 测试客户端
   2. DBServer/ 数据库处理服
   3. dependence/ 第三方依赖库
   4. FlatServer/ 平台方案服（跨平台转发协议用，暂未实现）
   5. GameServer/ 场景服务器
   6. GatewayServer/ 网关服务器
   7. HelpTools/ 工具项目（用于生成数据、处理数据辅助开发用）
   8. Include/ 共用引入文件
   9. LibNetMysql/ Mysql数据库封装类库
   10. LibNetSocket/ Socket封装类库
   11. LibProtocol/ Protocol协议类目录
   12. LibSrvcore/ 本项目共用类库
   13. LoginServer/ 登录服务器
   14. LogServer/ 日志服务器（数据库日志、暂未实现）
   15. MQServer/ 消息队列服务器（处理外部可延时事件，持久例事件处理，如充值、后台调用等；暂未实现）
   16. ShiftServer/ 区域管理服务器（暂未实现）
   17. sql/ 数据库更新记录目录
   18. WorldServer/ 世界服务器

# 服务器层级介绍
                                平台服               <-----------平台服-------->Mysql(管理后台数据库)
                                  |
                               /      \
                           区域服1   区域服2
                                |
                             /     \                               世界服、数据服、登录服
                          世界服1  世界服N           <------------------------>Mysql（游戏数据库）
                         / | \  \
                        /  |  \  | \
                       /   |   \ |   \
                   场景服1 场景服N \ <-> 数据服 <-> 登录服 
                       \   \     |     ---       /
                            \    |(世界服)       /
                             \   |             /
                            网关服1         网关服N

# GameService.cpp 总管理器文件
1. 聚合了大部分该服务器的管理类，所有资源都需要从NetSerivce中获得，这样做的目的是将资源都聚合在一起，提供统一接口，方便记忆与管理，比如：你所找要的资源->NetSerivces实例对象->get各个资源类->get所需要的资源
2. GameService也包括了main函数，启动程序的入口
3. serivces.xml配置文件

 

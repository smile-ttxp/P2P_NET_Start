/**************************************************************************
* 版    权： 	Copyright (c) 2018 FTC.
* 文件名称：	FTCSock.h
* 文件标识： 
* 内容摘要：	socket接口封装
* 其它说明： 
* 当前版本：	V1.0
* 作    者：	hly2070
* 完成日期：	2018年05月 03日
*
* 修改记录1	：
* 修改日期：
* 版 本 号：
* 修 改 人：
* 修改内容：
**************************************************************************/

#ifndef __FTC_SOCK_H__
#define __FTC_SOCK_H__

#ifdef		__cplusplus
extern		"C"
{
#endif

/**************************************************************************
 *                         头文件引用                                     *
 **************************************************************************/
//#include <netinet/in.h>
#include "FTCTypedef.h"

/**************************************************************************
 *                        常量定义                                   *
 **************************************************************************/

/**************************************************************************
 *                         数据类型                                    *
 **************************************************************************/

/**************************************************************************
 *                        全局函数                                *
 **************************************************************************/
/**********************************************************************
* 函数名称：FTC_InetAddr
* 功能描述：字符串ip地址转整形ip地址
* 输入参数：pStrIp	字符串ip地址指针
* 输出参数：无
* 返 回 值：整形ip地址
* 其它说明： 
* 修改日期		  版本号	 修改人 	  修改内容
* -----------------------------------------------
* 2018/05/03	  V1.0		 hly2070	
***********************************************************************/
U32 FTC_InetAddr(S8 *pStrIp);

/**********************************************************************
* 函数名称：FTC_Htons
* 功能描述：短整形主机序转网络字节序
* 输入参数：nsVal 主机序值
* 输出参数：无
* 返 回 值：网络序值
* 其它说明： 
* 修改日期        版本号     修改人	      修改内容
* -----------------------------------------------
* 2018/05/04      V1.0	     hly2070  
***********************************************************************/
S16 FTC_Htons(S16 nsVal);

/**********************************************************************
* 函数名称：FTC_Htonl
* 功能描述：整形主机序转网络字节序
* 输入参数：niVal 主机序值
* 输出参数： 无
* 返 回 值：网络序值
* 其它说明： 
* 修改日期        版本号     修改人	      修改内容
* -----------------------------------------------
* 2018/05/04      V1.0	     hly2070
***********************************************************************/
S32 FTC_Htonl(S32 niVal);

/**********************************************************************
* 函数名称：FTC_Ntohs
* 功能描述：短整形网络序转主机字节序
* 输入参数：nsVal 网络字节序值
* 输出参数： 无
* 返 回 值：网络序值
* 其它说明： 
* 修改日期        版本号     修改人	      修改内容
* -----------------------------------------------
* 2018/05/04      V1.0	     hly2070
***********************************************************************/
S16 FTC_Ntohs(S16 nsVal);

/**********************************************************************
* 函数名称：FTC_Ntohl
* 功能描述：整形网络序转主机字节序
* 输入参数：niVal 网络字节序值
* 输出参数： 无
* 返 回 值：主机字节序
* 其它说明： 
* 修改日期        版本号     修改人	      修改内容
* -----------------------------------------------
* 2018/05/04      V1.0	     hly2070  
***********************************************************************/
S32 FTC_Ntohl(S32 niVal);

/**********************************************************************
* 函数名称：FTC_CreateUdpSock
* 功能描述：创建udp套接口
* 输入参数：uiLocalIp	   本地ip,网络字节序
*			usLocalPort    本地端口，网络字节序
* 输出参数：无
* 返 回 值：套接口描述符
* 其它说明： 
* 修改日期		  版本号	 修改人 	  修改内容
* -----------------------------------------------
* 2018/05/03	  V1.0		 hly2070	
***********************************************************************/
S32 FTC_CreateUdpSock(U32 uiLocalIp, U16 usLocalPort);

/**********************************************************************
* 函数名称：FTC_SelectRead
* 功能描述：超时等待套接口可读
* 输入参数：niFd   套接口描述符
*           niTimeout     等待时间，单位:微妙
* 输出参数：无
* 返 回 值：0:表示可读 -1:表示不可读
* 其它说明： 
* 修改日期        版本号     修改人	      修改内容
* -----------------------------------------------
* 2018/05/04	  V1.0		 hly2070  
***********************************************************************/
S32 FTC_SelectRead(SOCKET niFd, S32 niTimeout);

/**********************************************************************
* 函数名称：FTC_Recvfrom
* 功能描述：接收udp数据
* 输入参数：sockfd   套接口描述符
*           pBuf     接收数据缓冲区
*           niSize   接收数据缓冲区大小
*           pRemoteIp  远端ip地址指针
*			pRemotePort 远端port指针
* 输出参数：pBuf  接收数据缓冲区
*      		pRemoteIp 远端ip地址，网络字节序
*			pRemotePort 远端端口，网络字节序
* 返 回 值：接收数据长度，-1:表示失败
* 其它说明： 
* 修改日期        版本号     修改人	      修改内容
* -----------------------------------------------
* 2018/05/04	  V1.0		 hly2070  
***********************************************************************/
S32 FTC_Recvfrom(SOCKET sockfd, S8 *pBuf, S32 niSize, U32 *pRemoteIp, U16 *pRemotePort);

/**********************************************************************
* 函数名称：FTC_Recvfrom2
* 功能描述：接收udp数据
* 输入参数：sockfd   套接口描述符
*           pBuf     接收数据缓冲区
*           niSize   接收数据缓冲区大小
*           readAddr 保存远端socket地址
* 输出参数：pBuf  接收数据缓冲区
*      		readAddr 保存远端socket地址
* 返 回 值：接收数据长度，-1:表示失败
* 其它说明： 
* 修改日期        版本号     修改人	      修改内容
* -----------------------------------------------
* 2018/05/04	  V1.0		 hly2070  
***********************************************************************/
S32 FTC_Recvfrom2(SOCKET sockfd, S8 *pBuf, S32 niSize, struct sockaddr_in *readAddr);

/**********************************************************************
* 函数名称：FTC_CloseSock
* 功能描述：关闭套接口
* 输入参数：niSockfd   套接口描述符
* 输出参数：无
* 返 回 值：无
* 其它说明： 
* 修改日期        版本号     修改人	      修改内容
* -----------------------------------------------
* 2018/05/04	  V1.0		 hly2070  
***********************************************************************/
void FTC_CloseSock(SOCKET niSockfd);

/**********************************************************************
* 函数名称：FTC_Sendto
* 功能描述：发送udp数据
* 输入参数：sockfd   套接口描述符
*           pBuf      发送数据缓冲区
*			niSize    发送数据字节数
*			niRemoteIp  目的端ip, 网络字节序
*           usRemotePort 目的端端口，网络字节序
* 输出参数：无
* 返 回 值：发送数据长度
* 其它说明： 
* 修改日期        版本号     修改人	      修改内容
* -----------------------------------------------
* 2018/05/05	  V1.0		 hly2070  
***********************************************************************/
S32 FTC_Sendto(SOCKET sockfd, S8*pBuf, S32 niSize, U32 niRemoteIp, U16 usRemotePort);

/**********************************************************************
* 函数名称：FTC_Sendto2
* 功能描述：发送udp数据
* 输入参数：sockfd   套接口描述符
*           pBuf      发送数据缓冲区
*			niSize    发送数据字节数
*			remoteAddr 目标地址
* 输出参数：无
* 返 回 值：发送数据长度
* 其它说明： 
* 修改日期        版本号     修改人	      修改内容
* -----------------------------------------------
* 2018/05/05	  V1.0		 hly2070  
***********************************************************************/
S32 FTC_Sendto2(SOCKET sockfd, S8*pBuf, S32 niSize, struct sockaddr_in *remoteAddr);

#ifdef		__cplusplus
}
#endif

#endif


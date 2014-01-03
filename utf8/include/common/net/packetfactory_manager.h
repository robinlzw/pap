/**
 * PAP Engine ( https://github.com/viticm/pap )
 * $Id packetfactory_manager.h
 * @link https://github.com/viticm/pap for the canonical source repository
 * @copyright Copyright (c) 2013-2013 viticm( viticm@126.com )
 * @license
 * @user viticm<viticm@126.com>
 * @date 2014-1-3 10:11:38
 * @uses server and client net packet factory manager
 */
#ifndef PAP_COMMON_NET_PACKETFACTORY_H_
#define PAP_COMMON_NET_PACKETFACTORY_H_

#include "common/net/config.h"
#include "common/net/packetfactory.h"
#include "common/sys/thread.h"

namespace pap_common_net {

class PacketFactoryManager {

 public:
   PacketFactoryManager();
   ~PacketFactoryManager();

 public:
   uint32_t* packet_alloccount_;
 
 public:
   bool init();
   //根据消息类型从内存里分配消息实体数据（允许多线程同时调用）
   Packet* createpacket(uint16_t pakcetid);
   //根据消息类型取得对应消息的最大尺寸（允许多线程同时调用）
   uint32_t getpacket_maxsize(uint16_t packetid);
   //删除消息实体（允许多线程同时调用）
   void removepacket(Packet* packet);
   void lock();
   void unlock();

 private:
   PacketFactory** packetfactorys_;
   uint16_t size_;
   pap_common_sys::ThreadLock lock_;

 private:
   void addfactory(PacketFactory* factory);

};

}; //namespace pap_common_net

#endif //COMMON_NET_PACKETFACTORY_H_
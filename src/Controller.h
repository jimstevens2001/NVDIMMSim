#ifndef CONTROLLER_H
#define CONTROLLER_H
//Controller.h
//header file for controller

#include "SimulatorObject.h"
#include "SystemConfiguration.h"
#include "Ftl.h"
#include "Die.h"
#include "Channel.h"
#include "Transaction.h"

namespace SSDSim{
	typedef struct {
		Channel *channel;
		std::vector<Die *> dies;
	} Package;

	class Ssd;
	class Controller : public SimulatorObject{
		public:
			Controller(Ssd* parent);

			bool addTransaction(Transaction &trans);
			void attachPackages(vector<Package> *packages);
			void returnReadData(const Transaction &trans);
			void attachChannel(Channel *channel);
			void receiveFromChannel(BusPacket *busPacket);
			void update(void);
			Ssd *parentSsd;
		private:

			std::queue<Transaction> transactionQueue;
			std::vector<Transaction> returnTransaction;

			Ftl ftl;
			std::vector<Package> *packages;
			std::vector<std::queue <BusPacket *> > channelQueues;
			std::vector<BusPacket *> outgoingPackets;
			
			std::vector<uint> channelXferCyclesLeft;

	};
}
#endif

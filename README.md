# Siemens-5G-Final-Project
Milestone 1
 -  Generate a stream of ethernet packets and dump them in a text file, the format of the packet to be
dumped is explained later.
 -  Packets will be generated for a specific streaming duration
 -  Read packets configurations from a text file and they are sent in bursts
 -  Packets are to be sent in bursts
 -  Bursts will be sent periodically, till the end of streaming time
 -  Packets should be 4-byte aligned, meaning that the preamble of the ethernet packet should start at
multiples of 4-byte. (Hint: To align the start of packets, IFGs are sent as padding)
 -  If the period or the total streaming duration have ended while an ethernet packet is being
generated, the packet should be discarded and IFGs are sent instead
 -  The program will accept the following two arguments: 1. Configuration file: The relative or absolute
path of the file 2. Output file: The output file name
 -  Packets should be dumped into an output file in a 4-byte aligned format.
Milestone1
and this is the configuration file 
 -  Eth.LineRate //should be in Gigabits
 -  Eth.CaptureSizeMs //this is the time of generation, for example if it is 10 ms then 1 frame will
be generated
 -  Eth.MinNumOfIFGsPerPacket 
//IFG is at the end of each packet after CRC, and e.g : if min number of ifgs is 3 then after each
packet there should be 3 IFGs and you have to consider the alignment, so in this case if the packet
is not 4 byte aligned we need to add extra IFGs)
 -  Eth.DestAddress //(48-bit hex formatted e.g : 0x010101010101
 -  Eth.SourceAddress //48-bit hex formatted e.g: 0x333333333333
 -  Eth.MaxPacketSize // Packet size in bytes, includes the preamble, SoP, SRC Add, Dest Add,
ether type, payload, and CRC, if the packet size exceeds this number then fragmentation
should happen.
 -  Eth.BurstSize // Number of ethernet packets in one burst
 -  Eth.BurstPeriodicity_us // The periodicity of the burst in microseconds

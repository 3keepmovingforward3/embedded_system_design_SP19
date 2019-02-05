connect -url tcp:127.0.0.1:3121
source C:/Zynq_Book/bb_PmodAD1/bb_PmodAD1.sdk/design_1_wrapper_hw_platform_0/ps7_init.tcl
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo 210279A6A4FAA"} -index 0
loadhw -hw C:/Zynq_Book/bb_PmodAD1/bb_PmodAD1.sdk/design_1_wrapper_hw_platform_0/system.hdf -mem-ranges [list {0x40000000 0xbfffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo 210279A6A4FAA"} -index 0
stop
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo 210279A6A4FAA"} -index 0
rst -processor
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo 210279A6A4FAA"} -index 0
dow C:/Zynq_Book/bb_PmodAD1/bb_PmodAD1.sdk/bb_PmodAD1/Debug/bb_PmodAD1.elf
configparams force-mem-access 0
bpadd -addr &main

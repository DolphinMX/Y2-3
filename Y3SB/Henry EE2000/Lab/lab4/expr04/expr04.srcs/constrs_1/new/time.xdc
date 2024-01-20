# Timing Constraints
create_clock -period 10.000 -name Clock -waveform {0.000 5.000} [get_ports {clk}];
set_property PACKAGE_PIN Y9 [get_ports {clk}] ;
set_property IOSTANDARD LVCMOS33 [get_ports {clk}] ;
set_property PACKAGE_PIN R16 [get_ports {rst}] ;
set_property IOSTANDARD LVCMOS18 [get_ports {rst}];
set_property PACKAGE_PIN P16 [get_ports {ctrlButton}] ;
set_property IOSTANDARD LVCMOS18 [get_ports {ctrlButton}];
#Write your code here to complete this constraints file

set_property PACKAGE_PIN T22 [get_ports { led[0]}];
set_property IOSTANDARD LVCMOS33 [get_ports { led[0]}];
set_property PACKAGE_PIN T21 [get_ports { led[1]}];
set_property IOSTANDARD LVCMOS33 [get_ports { led[1]}];
set_property PACKAGE_PIN U22 [get_ports { led[2]}];
set_property IOSTANDARD LVCMOS33 [get_ports { led[2]}];
set_property PACKAGE_PIN U21 [get_ports { led[3]}];
set_property IOSTANDARD LVCMOS33 [get_ports { led[3]}];
set_property PACKAGE_PIN V22 [get_ports { led[4]}];
set_property IOSTANDARD LVCMOS33 [get_ports { led[4]}];
set_property PACKAGE_PIN W22 [get_ports { led[5]}];
set_property IOSTANDARD LVCMOS33 [get_ports { led[5]}];
set_property PACKAGE_PIN U19 [get_ports { led[6]}];
set_property IOSTANDARD LVCMOS33 [get_ports { led[6]}];
set_property PACKAGE_PIN U14 [get_ports { led[7]}];
set_property IOSTANDARD LVCMOS33 [get_ports { led[7]}];
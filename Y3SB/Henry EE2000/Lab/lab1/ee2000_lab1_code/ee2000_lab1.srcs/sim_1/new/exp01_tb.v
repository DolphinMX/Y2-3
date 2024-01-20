`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/20/2023 10:27:41 AM
// Design Name: 
// Module Name: exp01_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`timescale 1ns / 1ps
module exp01_tb();
reg switch;
wire led;
exp01 exp01_inst (.sw(switch), .led(led));
initial
begin
    #0 switch = 1'b0; // # means a time delay, so at 5ns, switch will be set to 1
    #5 switch = 1'b1;
    #10 switch = 1'b0;
    #15 $stop; // $stop will stop the simulation
    end
endmodule

----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/06/2023 09:10:55 AM
-- Design Name: 
-- Module Name: full_adder_1bit - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity full_adder_1bit is
    Port (
        i_A: in STD_LOGIC; 
        i_B: in STD_LOGIC; 
        i_Cin: in STD_LOGIC; 
        o_S: out STD_LOGIC; 
        o_Cout: out STD_LOGIC);
end full_adder_1bit;

architecture Behavioral of full_adder_1bit is

begin
    o_S <= i_Cin XOR i_A  XOR i_B;
    o_Cout <= (i_B AND i_A) OR ((i_B XOR i_A) AND i_Cin);

end Behavioral;

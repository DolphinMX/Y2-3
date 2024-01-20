----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/06/2023 09:35:46 AM
-- Design Name: 
-- Module Name: full_adder_4bits - Behavioral
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

entity full_adder_4bits is
    Port (
    i_A: in STD_LOGIC_VECTOR (3 DOWNTO 0); 
    i_B: in STD_LOGIC_VECTOR (3 DOWNTO 0); 
    i_Ci: in STD_LOGIC; 
    o_S: out STD_LOGIC_VECTOR (3 DOWNTO 0); 
    o_Cout: out STD_LOGIC 
    );
end full_adder_4bits;

architecture Behavioral of full_adder_4bits is
    SIGNAL ci: STD_LOGIC_VECTOR (3 DOWNTO 0); 
    COMPONENT full_adder_1bit is 
        Port ( 
            i_A: in STD_LOGIC; 
            i_B: in STD_LOGIC; 
            i_Cin: in STD_LOGIC; 
            o_S: out STD_LOGIC; 
            o_Cout: out STD_LOGIC 
            ); 
    END COMPONENT;

begin
    ci(0) <= i_Ci; 
    uut0: full_adder_1bit PORT MAP(i_A(0), i_B(0), ci(0), o_S(0), ci(1)); 
    uut1: full_adder_1bit PORT MAP(i_A(1), i_B(1), ci(1), o_S(1), ci(2)); 
    uut2: full_adder_1bit PORT MAP(i_A(2), i_B(2), ci(2), o_S(2), ci(3)); 
    uut3: full_adder_1bit PORT MAP(i_A(3), i_B(3), ci(3), o_S(3), o_Cout); 

end Behavioral;

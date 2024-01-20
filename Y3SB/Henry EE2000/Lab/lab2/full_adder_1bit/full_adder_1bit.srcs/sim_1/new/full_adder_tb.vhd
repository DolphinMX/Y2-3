----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/06/2023 10:09:04 AM
-- Design Name: 
-- Module Name: full_adder_tb - Behavioral
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

entity full_adder_tb is
--  Port ( );
end full_adder_tb;

architecture Behavioral of full_adder_tb is
    COMPONENT full_adder_4bits is 
        Port ( 
            i_A: in STD_LOGIC_VECTOR (3 DOWNTO 0); 
            i_B: in STD_LOGIC_VECTOR (3 DOWNTO 0); 
            i_Ci: in STD_LOGIC; 
            o_S: out STD_LOGIC_VECTOR (3 DOWNTO 0); 
            o_Cout: out STD_LOGIC );  
    End COMPONENT; 
    SIGNAL i_A: STD_LOGIC_VECTOR (3 DOWNTO 0); 
    SIGNAL i_B: STD_LOGIC_VECTOR (3 DOWNTO 0);  
    SIGNAL i_Ci: STD_LOGIC; 
    SIGNAL o_S: STD_LOGIC_VECTOR (3 DOWNTO 0);  
    SIGNAL o_Cout: STD_LOGIC; 

begin
    uut: full_adder_4bits PORT MAP (i_A, i_B, i_Ci, o_S, o_Cout);  
    siggen: PROCESS 
    begin
        i_A<="0101";
        i_B<="0111";
        i_Ci<='0';
        wait for 10ns;
        i_A<=o_S;
        i_B<="0001";
        wait for 10ns;
        i_A<=o_S;
        i_B<="0101";
        wait for 10ns;
        i_A<=o_S;
        i_B<="0010";
        i_Ci<='1';
         wait for 5 ns;
        i_A<=o_S;
        i_B<="0000"; 
         wait for 5 ns;
    end PROCESS siggen;  
end Behavioral;

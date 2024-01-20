----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/20/2023 10:29:15 AM
-- Design Name: 
-- Module Name: alu_tb - Behavioral
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

entity alu_tb is
--  Port ( );
end alu_tb;

architecture Behavioral of alu_tb is
COMPONENT alu is
Port (
 A: in STD_LOGIC_VECTOR (2 DOWNTO 0);
 B: in STD_LOGIC_VECTOR (2 DOWNTO 0);
 op: in STD_LOGIC_VECTOR (1 DOWNTO 0);
 result: out STD_LOGIC_VECTOR (2 DOWNTO 0);
 carry: out STD_LOGIC;
 dup_result:out STD_LOGIC_VECTOR (2 DOWNTO 0); 
 dup_carry: out STD_LOGIC
);
 End COMPONENT;
 SIGNAL A: STD_LOGIC_VECTOR (2 DOWNTO 0);
 SIGNAL B: STD_LOGIC_VECTOR (2 DOWNTO 0);
 SIGNAL op: STD_LOGIC_VECTOR (1 DOWNTO 0);
 SIGNAL result: STD_LOGIC_VECTOR (2 DOWNTO 0); 
 SIGNAL carry: STD_LOGIC;
 SIGNAL dup_result: STD_LOGIC_VECTOR (2 DOWNTO 0);
 SIGNAL dup_carry: STD_LOGIC; 

begin
    uut: ALU PORT MAP (A, B, op, result, carry, dup_result, dup_carry);
simgen: process
begin

    A <= "011";
    B <= "110";
    op <= "00";
    wait for 10ns;
    A <= "110";
    wait for 10ns;
    B <= "010";
    wait for 10ns;
    op <= "11";
    wait for 50ns;
    op <= "01";
    A <= "110";
    B <= "111";
    wait;
    end process simgen;
end Behavioral;

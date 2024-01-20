----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/19/2018 04:36:04 PM
-- Design Name: 
-- Module Name: alu - Behavioral
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity alu is
    Port (
    A: in STD_LOGIC_VECTOR (2 DOWNTO 0);
    B: in STD_LOGIC_VECTOR (2 DOWNTO 0);
    op: in STD_LOGIC_VECTOR (1 DOWNTO 0);
    result: out STD_LOGIC_VECTOR (2 DOWNTO 0);
    carry: out STD_LOGIC;
    dup_result: out STD_LOGIC_VECTOR (2 DOWNTO 0);
    dup_carry: out STD_LOGIC
);
end alu;

architecture Behavioral of alu is

signal result_t : std_logic_vector (2 downto 0);
signal carry_t: std_logic;
signal tmp: std_logic_vector(3 downto 0);

begin
    dup_result <= result_t;
    dup_carry <= carry_t;
    result <= result_t;
    carry <= carry_t;
    tmp <= ('0' & A) + ('0' & B);
    with op select result_t <=
        A + B when "00",
        A AND B when "01",
        A XOR B when "10",
        to_stdlogicvector(to_bitvector(A) sll 1) when "11",
        "ZZZ" when others;
    with op select carry_t <=
        tmp(3) when "00",
        '0' when others; 
end Behavioral;

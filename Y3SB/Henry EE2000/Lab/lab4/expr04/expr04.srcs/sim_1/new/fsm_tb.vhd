----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/03/2023 09:30:31 AM
-- Design Name: 
-- Module Name: fsm_tb - Behavioral
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

entity fsm_tb is
--  Port ( );
end fsm_tb;

architecture Behavioral of fsm_tb is 
  component fsm is 
Port (
   clk : in STD_LOGIC;
   rst :  in STD_LOGIC;
   ctrlButton : in STD_LOGIC;
   led : out STD_LOGIC_VECTOR (7 DOWNTO 0)
);
  end component;
  signal clk : STD_LOGIC;
  signal rst : STD_LOGIC;
  signal ctrlButton : STD_LOGIC;
  signal led : STD_LOGIC_VECTOR (7 DOWNTO 0);

begin
  uut: fsm port map (clk=>clk, rst=>rst, ctrlButton=>ctrlButton, led=>led);
  
clk_gen: process
  begin
    clk <= '0';
    wait for 5ns;
    clk <= '1';
    wait for 5ns;
  end process;
 
  rst <= '0';
 
  sig_gen: process
  begin
    ctrlButton <= '0';
    wait for 90ns;
    ctrlButton <= '1';
    wait for 10ns;
    ctrlButton <= '0';
    wait for 20ns;
  end process;


end Behavioral;

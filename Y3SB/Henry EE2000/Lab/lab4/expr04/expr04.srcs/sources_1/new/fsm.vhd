library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
entity fsm is
Port (
clk: in STD_LOGIC;
rst: in STD_LOGIC;
ctrlButton: in STD_LOGIC;
led: out STD_LOGIC_VECTOR (7 DOWNTO 0)
);
end fsm;

Architecture Behavioral of fsm is

Constant TIME_10ms: integer := 10;
Signal key_counter: integer range 0 to 1000001;
Signal btnDetection: boolean;
type states is (zero, one, two, three, four, five, six, seven);
signal present_state, next_state: states;

begin

    Key_detection: process (clk)
    begin
        if rising_edge(clk) then --Clock event, used to describe sequential logic.
            if (ctrlButton='1') then
                key_counter <= 0;
            elsif (ctrlButton='0') and (key_counter <= TIME_10MS) then
                key_counter <= key_counter +1;
            end if;
       end if;
    end process;
btnDetection <= (key_counter = TIME_10ms);

state_transition: process (rst, clk)
begin
    if (rst='1') then
        present_state<=zero;
    elsif (rising_edge(clk) and btnDetection = true ) then
        present_state<=next_state;
    end if;
end process;

decoder: process (present_state)
begin
case present_state is
    when zero=> led<= "00000101";
    next_state<= one;
    when one=> led<= "00000111";
    next_state<= two;
    when two=> led<= "00000001";
    next_state<= three;
    when three=> led<= "00000101";
    next_state<= four;
    when four=> led<= "00000010";
    next_state<= five;
    when five=> led<= "00000000";
    next_state<= six;
    when six=> led<= "00000111";
    next_state<= seven;
    when seven=> led<= "00001001";
    next_state<= zero;
--Write your code here to assign LED and next_state
end case;
end process;
end Behavioral;
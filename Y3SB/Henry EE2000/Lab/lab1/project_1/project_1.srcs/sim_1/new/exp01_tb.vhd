entity exp01_tb is 
end exp01_tb;
architecture Behavioral of exp01_tb is
-- component declaration 
component exp01 is
    Port (
        sw: IN BIT; 
        led: OUT BIT
    );
end component;
-- signal declaration 
signal sw: BIT; 
signal led: BIT; 
begin
exp01_inst: exp01
    port map (
        sw => sw,
        led => led
);
simgen: process
begin
    sw <= '0';
    wait for 150ns;
    sw <= '1';
    wait for 200ns;
    sw <= '0';
    wait for 150ns;
end process;
end Behavioral;
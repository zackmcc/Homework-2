-- ECE532 HW2
-- Zackary McClamma
--04-Sep-2019

library ieee;
  use ieee.std_logic_1164.all;

entity homework2 is
  port
  (
    i_clk     : in    std_logic;
    i_rst_n   : in    std_logic;
	 disp1_input0 : out std_logic;
	 disp1_input1 : out std_logic;
	 disp1_input2 : out std_logic;
	 disp1_input3 : out std_logic;
	 disp1_input4 : out std_logic;
	 disp1_input5 : out std_logic;
	 disp1_input6 : out std_logic;
	 disp2_input0 : out std_logic;
	 disp2_input1 : out std_logic;
	 disp2_input2 : out std_logic;
	 disp2_input3 : out std_logic;
	 disp2_input4 : out std_logic;
	 disp2_input5 : out std_logic;
	 disp2_input6 : out std_logic;
	 button : in std_logic
	 
  );
end homework2;

architecture sch of homework2 is

  component homework2_cpu is
  port (
    clk_clk       : in std_logic;
    reset_reset_n : in std_logic;
	 disp1_input0_export : out std_logic;
	 disp1_input1_export : out std_logic;
	 disp1_input2_export : out std_logic;
	 disp1_input3_export : out std_logic;
	 disp1_input4_export : out std_logic;
	 disp1_input5_export : out std_logic;
	 disp1_input6_export : out std_logic;
	 disp2_input0_export : out std_logic;
	 disp2_input1_export : out std_logic;
	 disp2_input2_export : out std_logic;
	 disp2_input3_export : out std_logic;
	 disp2_input4_export : out std_logic;
	 disp2_input5_export : out std_logic;
	 disp2_input6_export : out std_logic;
	 button_export : in std_logic
  );
  end component homework2_cpu;
  
  signal w_disp1_input0 : std_logic;
  signal w_disp1_input1 : std_logic;
  signal w_disp1_input2 : std_logic;
  signal w_disp1_input3 : std_logic;
  signal w_disp1_input4 : std_logic;
  signal w_disp1_input5 : std_logic;
  signal w_disp1_input6 : std_logic;
  
begin

	disp1_input0 <= w_disp1_input0;
	disp1_input1 <= w_disp1_input1;
	disp1_input2 <= w_disp1_input2;
	disp1_input3 <= w_disp1_input3;
	disp1_input4 <= w_disp1_input4;
	disp1_input5 <= w_disp1_input5;
	disp1_input6 <= w_disp1_input6;
	
  u0 : component homework2_cpu
	port map 
  (
    clk_clk       => i_clk,
    reset_reset_n => i_rst_n,
	 disp1_input0_export => w_disp1_input0,
	 disp1_input1_export => w_disp1_input1,
	 disp1_input2_export => w_disp1_input2,
	 disp1_input3_export => w_disp1_input3,
	 disp1_input4_export => w_disp1_input4,
	 disp1_input5_export => w_disp1_input5,
	 disp1_input6_export => w_disp1_input6,
	 disp2_input0_export => disp2_input0,
	 disp2_input1_export => disp2_input1,
	 disp2_input2_export => disp2_input2,
	 disp2_input3_export => disp2_input3,
	 disp2_input4_export => disp2_input4,
	 disp2_input5_export => disp2_input5,
	 disp2_input6_export => disp2_input6,
	 button_export => button
  );

end sch;

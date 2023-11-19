--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:09:32 11/09/2023
-- Design Name:   
-- Module Name:   Z:/OneDrive/Documentos/GitHub/ZX81KBD-PLUS/ZX81KBD-PLUS/zx81kbdtb.vhd
-- Project Name:  ZX81KBD-PLUS
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: zx81kbdplus
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY zx81kbdtb IS
END zx81kbdtb;
 
ARCHITECTURE behavior OF zx81kbdtb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT zx81kbdplus
    PORT(
         D : OUT  std_logic_vector(4 downto 0);
         C : IN  std_logic_vector(4 downto 0);
         CLK : IN  std_logic;
         RST : IN  std_logic;
         A : IN  std_logic_vector(15 downto 8);
         A0 : IN  std_logic;
         nIORQ : IN  std_logic;
         nRD : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal C : std_logic_vector(4 downto 0) := (others => '0');
   signal CLK : std_logic := '0';
   signal RST : std_logic := '0';
   signal A : std_logic_vector(15 downto 8) := (others => '0');
   signal A0 : std_logic := '0';
   signal nIORQ : std_logic := '0';
   signal nRD : std_logic := '0';

 	--Outputs
   signal D : std_logic_vector(4 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN

 
	-- Instantiate the Unit Under Test (UUT)
   uut: zx81kbdplus PORT MAP (
          D => D,
          C => C,
          CLK => CLK,
          RST => RST,
          A => A,
          A0 => A0,
          nIORQ => nIORQ,
          nRD => nRD
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
		RST <= 0;
      wait for 100 ns;	
		
      wait for CLK_period*10;

      -- insert stimulus here 
		C <= 5'b00110;
		CLK_process;
		C <= 5'b00110;
		CLK_process;
		C <= 5'b11000;
		CLK_process;
		C <= 5'b11110;
		CLK_process;
		C <= 5'b01011;
		CLK_process;
		C <= 5'b01011;
		CLK_process;
		C <= 5'b11111;
		CLK_process;
		C <= 5'b11111;
		CLK_process;
      wait;
   end process;

END;

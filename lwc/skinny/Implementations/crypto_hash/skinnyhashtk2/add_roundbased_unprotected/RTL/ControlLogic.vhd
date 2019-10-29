--
-- SKINNY-Hash Reference Hardware Implementation
-- 
-- Copyright 2019:
--     Amir Moradi & Pascal Sasdrich for the SKINNY Team
--     https://sites.google.com/site/skinnycipher/
-- 
-- This program is free software; you can redistribute it and/or
-- modify it under the terms of the GNU General Public License as
-- published by the Free Software Foundation; either version 2 of the
-- License, or (at your option) any later version.
-- 
-- This program is distributed in the hope that it will be useful, but
-- WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
-- General Public License for more details.
-- 


-- IMPORTS
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;



-- ENTITY
----------------------------------------------------------------------------------
ENTITY ControlLogic IS
	PORT ( CLK			: IN	STD_LOGIC;
			 -- CONTROL PORTS --------------------------------
		  	 RESET		: IN  STD_LOGIC;
		    DONE			: OUT STD_LOGIC;
			 -- CONST PORT -----------------------------------
          ROUND_CST	: OUT STD_LOGIC_VECTOR (5 DOWNTO 0));
END ControlLogic;



-- ARCHITECTURE : ROUND
----------------------------------------------------------------------------------
ARCHITECTURE Round OF ControlLogic IS

	-- SIGNALS --------------------------------------------------------------------
	SIGNAL STATE, UPDATE : STD_LOGIC_VECTOR(5 DOWNTO 0);

BEGIN

	-- STATE ----------------------------------------------------------------------
	REG : PROCESS(CLK) BEGIN
		IF RISING_EDGE(CLK) THEN
			IF (RESET = '1') THEN
				STATE <= "000000";
			ELSE
				STATE <= UPDATE;
			END IF;
		END IF;
	END PROCESS;
	-------------------------------------------------------------------------------

	-- UPDATE FUNCTION ------------------------------------------------------------
	UPDATE 	<= STATE(4 DOWNTO 0) & (STATE(5) XNOR STATE(4));

	-- CONSTANT -------------------------------------------------------------------
	ROUND_CST <= UPDATE;

	-- DONE SIGNAL ----------------------------------------------------------------
	DONE <= '1' WHEN (UPDATE = "000100") ELSE '0';

END Round;

`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:27:03 11/09/2023
// Design Name:   zx81kbdplus
// Module Name:   Z:/OneDrive/Documentos/GitHub/ZX81KBD-PLUS/ZX81KBD-PLUS/zx81kbdtb.v
// Project Name:  ZX81KBD-PLUS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: zx81kbdplus
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module zx81kbdtb;

	// Inputs
	reg [4:0] C;
	reg CLK;
	reg RST;
	reg [15:8] A;
	reg A0;
	reg nIORQ;
	reg nRD;

	// Outputs
	wire [4:0] D;

	// Instantiate the Unit Under Test (UUT)
	zx81kbdplus uut (
		.D(D), 
		.C(C), 
		.CLK(CLK), 
		.RST(RST), 
		.A(A), 
		.A0(A0), 
		.nIORQ(nIORQ), 
		.nRD(nRD)
	);
	
	task read_keys;
		integer i;
		begin
			A = 8'hff;
			A0 = 1'b0;
			nIORQ = 1'b0;
			#10;
			nRD = 1'b0;
			#10;
			A = 8'b11111110;
			#10;
			nRD = 1'b1;
			#10;
			nRD = 1'b0;
			#10;
			A = 8'b11111101;
			#10;
			nRD = 1'b1;
			#10;
			nRD = 1'b0;
			#10;
			A = 8'b11111011;
			#10;
			nRD = 1'b1;
			#10;
			nRD = 1'b0;
			#10;
			A = 8'b11110111;
			#10;
			nRD = 1'b1;
			#10;
			nRD = 1'b0;
			#10;
			A = 8'b11101111;
			#10;
			nRD = 1'b1;
			#10;
			nRD = 1'b0;
			#10;
			A = 8'b11011111;
			#10;
			nRD = 1'b1;
			#10;
			nRD = 1'b0;
			#10;
			A = 8'b10111111;
			#10; 
			nRD = 1'b1;
			#10;
			nRD = 1'b0;
			#10;
			A = 8'b01111111;
			#10;
			nRD = 1'b1;
			#10;
		end
	endtask
	
	always begin
		read_keys;
	end;

	initial begin
		// Initialize Inputs
		C = 5'b11111;
		CLK = 0;
		RST = 0;
		A = 0;
		A0 = 1;
		nIORQ = 0;
		nRD = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		RST = 0;
		#100;
		RST = 1;
		#100;
		CLK = 0;
		#100;
		CLK = 1;
		#100;
		C = 5'b00110;
		#100;
		CLK = 0;
		#100;
		CLK = 1;
		#100;
		C = 5'b00110;
		#100;
		CLK = 0;
		#100;
		CLK = 1;
		#100;
		C = 5'b11000;
		#100;
		CLK = 0;
		#100;
		CLK = 1;
		#100;
		C = 5'b11110;
		#100;
		CLK = 0;
		#100;
		CLK = 1;
		#100;
		C = 5'b01011;
		#100;
		CLK = 0;
		#100;
		CLK = 1;
		#100;
		C = 5'b01011;
		#100;
		CLK = 0;
		#100;
		CLK = 1;
		#100;
		C = 5'b11111;
		#100;
		CLK = 0;
		#100;
		CLK = 1;
		#100;
		C = 5'b11111;
		#100; 

//		A0 <= 1'b0;
//		A <= 8'hff;
//		A[0] <= 1'b0;
//		#100;
//		A0 <= 1'b1;
	end
      
endmodule


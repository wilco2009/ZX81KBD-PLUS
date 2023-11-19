`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:20:27 11/08/2023 
// Design Name: 
// Module Name:    zx81kbd-plus 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module zx81kbdplus(
    output[4:0] D,
    input [4:0] C,
    input CLK,
	 input RST,
    input [15:8] A,
    input A0,
    input nIORQ,
    input nRD,
	 output TEST1,
	 output TEST2,
	 output TEST3
    );
	 
	wire kbdint;
	reg [2:0] n =0;
	reg [4:0] rows [0:7];
	reg [4:0] data;
	integer i;
	
	
	always@(posedge CLK or negedge RST) begin
		if (RST==0) n = 0;
		else begin
			//rows[n]<=C;
			rows[n]=C;
			n=n+1;
		end
	end
	
	
	assign kbdint = ~nIORQ & ~nRD & ~A0;
	
	always@(posedge kbdint) begin
		data = 5'b11111;
		for (i=7;i>=0;i=i-1)
			if (!A[8+i]) data = data & rows[i];
	end
	assign TEST1 = kbdint;
	assign TEST2 = data[0];
	assign TEST3 = data[1];
	assign D[0] = kbdint & !data[0]?  1'b0: 1'bz;
	assign D[1] = kbdint & !data[1]?  1'b0: 1'bz;
	assign D[2] = kbdint & !data[2]?  1'b0: 1'bz;
	assign D[3] = kbdint & !data[3]?  1'b0: 1'bz;
	assign D[4] = kbdint & !data[4]?  1'b0: 1'bz;
endmodule

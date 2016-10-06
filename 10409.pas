type dadu=record
		north,south,west,east,top,bottom:longint;
	end;

var x,y,temp:longint;
	dice:dadu;
	command:string;
	
begin
	repeat
		readln(x);
		if x<>0 then
		begin
			dice.top:=1;
			dice.north:=2;
			dice.west:=3;
			dice.east:=4;
			dice.south:=5;
			dice.bottom:=6;
			
			for y:=1 to x do
			begin
				readln(command);
				case command[1] of
				'n' : begin
						temp:=dice.top;
						dice.top:=dice.south;
						dice.south:=dice.bottom;
						dice.bottom:=dice.north;
						dice.north:=temp;
					  end;
					  
				'e' : begin
						temp:=dice.top;
						dice.top:=dice.west;
						dice.west:=dice.bottom;
						dice.bottom:=dice.east;
						dice.east:=temp;
					  end;
					  
				's' : begin
						temp:=dice.top;
						dice.top:=dice.north;
						dice.north:=dice.bottom;
						dice.bottom:=dice.south;
						dice.south:=temp;
					  end;
					  
				'w' : begin
						temp:=dice.top;
						dice.top:=dice.east;
						dice.east:=dice.bottom;
						dice.bottom:=dice.west;
						dice.west:=temp;
					  end;
				end;
			end;
			writeln(dice.top);
		end;
	until x=0;
end.
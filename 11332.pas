var x,y:longint;
	temp:string;
	
begin
	repeat
		readln(x);
		if x<>0 then
		begin
			while x>9 do
			begin
				str(x,temp);
				x:=0;
				for y:=1 to length(temp) do x:=x+(ord(temp[y])-ord('0'));
			end;
			writeln(x);
		end;
	until x=0;
end.
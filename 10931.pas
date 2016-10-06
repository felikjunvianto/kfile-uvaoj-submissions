var x,count:longint;
	hasil:string;
	
begin
	repeat
		readln(x);
		if x<>0 then
		begin
			delete(hasil,1,length(hasil));
			count:=0;
			while x<>0 do
			begin
				hasil:=chr((x mod 2)+48)+hasil;
				if x mod 2 = 1 then inc(count);
				x:=x div 2;
			end;
			writeln('The parity of ',hasil,' is ',count,' (mod 2).');
			x:=1;
		end;
	until x=0;
end.
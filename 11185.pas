var n:longint;
	x:string;
	
begin
	repeat
		readln(n);
		if n>=0 then
		begin
			delete(x,1,length(x));
			repeat
				x:=chr((n mod 3)+48) +x;
				n:=n div 3;
			until n=0;
			writeln(x);
		end;
	until n<0;
end.
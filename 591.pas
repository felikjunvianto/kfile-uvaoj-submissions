var n,x,y,mov,count:longint;
	stack:array[1..50] of longint;
	
begin
	count:=0;
	repeat
		readln(n);
		if n<>0 then 
		begin
			fillchar(stack,sizeof(stack),0);
			inc(count);
			y:=0;
			for x:=1 to n do 
			begin
				read(stack[x]);
				y:=y+stack[x];
			end;
			y:= y div n;
			
			mov:=0;
			for x:=1 to n do if stack[x]>y then mov:=mov+(stack[x]-y);
			writeln('Set #',count);
			writeln('The minimum number of moves is ',mov,'.');
			writeln;
		end;
	until n=0;
end.
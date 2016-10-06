var x,y,z,bilangan:longint;
	prime:array[1..1000000]of boolean;
	pembagi:array[1..78498] of longint;
	
begin
	for x:=1 to 1000000 do prime[x]:=TRUE;
	prime[1]:=FALSE;
	for x:=1 to 1000000 do if prime[x] then
	begin
		z:=2;
		while (z*x)<=1000000 do
		begin
			prime[z*x]:=FALSE;
			inc(z);
		end;
	end;
	
	y:=0;
	for x:=1 to 1000000 do if prime[x] then 
	begin 
		inc(y);
		pembagi[y]:=x;
	end;
	
	repeat
		readln(x);
		if x<>0 then
		begin
			bilangan:=x;
			z:=0;
			y:=0;
			repeat
				inc(y);
				if x mod pembagi[y] = 0 then
				begin
					inc(z);
					while x mod pembagi[y] = 0 do x:= x div pembagi[y];
				end;
			until x=1;
			writeln(bilangan,' : ',z);
		end;
	until x=0;
end.
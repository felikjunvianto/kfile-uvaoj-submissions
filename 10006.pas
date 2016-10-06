const car:array[1..15] of longint=(561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973);

var x,z:longint;
	prime:array[1..65000] of boolean;
	benar:boolean;
	
begin
	for x:=1 to 65000 do prime[x]:=TRUE;
	prime[1]:=FALSE;
	for x:=1 to 65000 do if prime[x] then
	begin
		z:=2;
		while x*z<=65000 do
		begin
			prime[x*z]:=FALSE;
			inc(z);
		end;
	end;
	
	repeat
		readln(x);
		if x<>0 then
		begin
			benar:=TRUE;
			if not prime[x] then
				for z:=1 to 15 do if x=car[z] then
				begin
					benar:=FALSE;
					break;
				end;
			if benar then writeln(x,' is normal.') else
				writeln('The number ',x,' is a Carmichael number.');
		end;
	until x=0;
end.
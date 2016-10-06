var a,b:ansistring;
	x,y:longint;
	dp:array[1..1000,1..1000] of longint;
	
function max(x,y:longint):longint;
	begin
		max:=x;
		if max<y then max:=y;
	end;
	
function panjang(i,j:longint):longint;
	begin
		if((i<=length(a))and(j<=length(b))) then
		begin
			if dp[i,j]=-1 then
			begin
				if a[i]=b[j] then dp[i,j]:=1+panjang(i+1,j+1) else
					dp[i,j]:=max(panjang(i+1,j),panjang(i,j+1));
			end;
			panjang:=dp[i,j];
		end else panjang:=0;
	end;
	
begin
	while not(eof) do
	begin
		readln(a);
		readln(b);
		for x:=1 to 1000 do
			for y:=1 to 1000 do dp[x,y]:=-1;
		writeln(panjang(1,1));
	end;
end.
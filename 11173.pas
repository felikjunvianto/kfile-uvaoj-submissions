var x,n,k,y,hasil,a,b,c:longint;

begin
	readln(x);
	for y:=1 to x do
	begin
		readln(n,k);
		inc(k);
		hasil:=0;
		for c:=1 to n do
		begin
			a:=1 shl (c-1);
			b:=0;
			if k > a then
			begin
				b:=(k-a) div (1 shl c);
				if (k-a) mod (1 shl c) > 0 then inc(b);
				if odd(b) then hasil:=hasil+(1 shl (c-1));
			end;
		end;
		writeln(hasil);
	end;
end.
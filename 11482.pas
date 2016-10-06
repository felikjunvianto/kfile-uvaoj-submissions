var m,n,x,y,z,count_m,count_n,a,b:longint;

begin
	a:=0;
	repeat
		readln(m,n);
		if((m<>0)and(n<>0)) then
		begin
			inc(a);
			writeln('Triangular Museum ',a);
			count_m:=0;
			count_n:=1;
			for x:=1 to m*n do
			begin
				for y:=m*n-1 downto x do write(' ');
				
				inc(count_m);
				if count_m>m then 
				begin
					count_m:=1;
					inc(count_n);
				end;
				for b:=1 to 2*(count_n)-1 do if odd(b) then
				begin		
					if count_m = 1 then write('/\') else 
					if count_m = m then
					begin
						write('/');
						for z:=1 to 2*(m-1) do write('_');
						write('\');
					end
					else
					begin
						write('/');
						for z:=1 to 2*(count_m-1) do write(' ');
						write('\');
					end;
				end
				else
				begin
					for z:=2*(m-count_m) downto 1 do write(' ');
				end;
				writeln;
			end;
			writeln;
		end;
	until((m=0)and(n=0));
end.
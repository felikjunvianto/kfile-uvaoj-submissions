

var n,b,h,w,x,y,biaya,harga:longint;
	week:array[1..13] of longint;
	ketemu:boolean;
	
begin
	while not(eof) do
	begin
		readln(n,b,h,w);
		ketemu:=false;
		biaya:=2000000;
		
		for x:=1 to h do
		begin
			readln(harga);
			fillchar(week,sizeof(week),0);
			for y:=1 to w-1 do read(week[y]);
			readln(week[w]);
			
			if ((b>=harga*n) and (harga*n<biaya)) then
				for y:=1 to w do if week[y]>=n then
				begin
					biaya:=harga*n;
					ketemu:=TRUE;
					break;
				end;
		end;
		if not(ketemu) then writeln('stay home') else writeln(biaya);
	end;
end.
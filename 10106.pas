var x,y:array[1..250] of integer;
	hasil:array[1..500] of integer;
	temp:string;
	a,b,c,sisa,d,e:integer;
	
begin
	while not(eof) do
	begin
		fillchar(hasil,sizeof(hasil),0);
		fillchar(x,sizeof(x),0);
		fillchar(y,sizeof(y),0);
		readln(temp);
		for a:=1 to length(temp) do val(temp[length(temp)-a+1],x[a],b);
		readln(temp);
		for c:=1 to length(temp) do val(temp[length(temp)-c+1],y[c],b);
		
		sisa:=0;
		for d:=1 to a+1 do
			for e:=1 to c+1 do
			begin
				hasil[d+e-1]:=hasil[d+e-1]+(x[d]*y[e])+sisa;
				if hasil[d+e-1]>9 then
				begin
					sisa:=hasil[d+e-1] div 10;
					hasil[d+e-1]:=hasil[d+e-1] mod 10;
				end else sisa:=0;
			end;
			
		for b:= 500 downto 1 do if hasil[b]<>0 then break;
		for a:=b downto 1 do write(hasil[a]);
		writeln;
	end;
end.
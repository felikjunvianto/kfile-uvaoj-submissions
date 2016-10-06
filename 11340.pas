var n,x,y,sum,t,kalimat:longint;
	bagi:real;
	harga:array[1..300] of longint;
	c:char;
	
begin
	readln(n);
	for x:=1 to n do
	begin
		readln(t);
		fillchar(harga,sizeof(harga),0);
		for y:=1 to t do 
		begin
			read(c);
			readln(harga[ord(c)]);
		end;
		
		sum:=0;
		readln(kalimat);
		for y:=1 to kalimat do 
		begin 
			while not(eoln) do
			begin
				read(c);
				if (harga[ord(c)] <> 0) then inc(sum,harga[ord(c)]);
			end;
			readln;
		end;
		
		bagi:=sum/100;
		writeln(bagi:0:2,'$');
	end;
end.
	
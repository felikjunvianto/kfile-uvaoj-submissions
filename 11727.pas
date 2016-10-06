var x,y:integer;
	gaji:array[1..3] of integer;
	
procedure quicksort(terkiri,terkanan:integer);
	var kiri,kanan,temp,pivot:integer;
	
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=gaji[(kiri+kanan) div 2];
			
			while kiri<=kanan do
			begin
				while gaji[kiri]<pivot do inc(kiri);
				while gaji[kanan]>pivot do dec(kanan);
				
				if kiri<=kanan then
				begin
					temp:=gaji[kiri];
					gaji[kiri]:=gaji[kanan];
					gaji[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			quicksort(terkiri,kanan);
			quicksort(kiri,terkanan);
		end;
	end;
	
begin
	readln(x);
	for y:=1 to x do
	begin
		readln(gaji[1],gaji[2],gaji[3]);
		quicksort(1,3);
		writeln('Case ',y,': ',gaji[2]);
	end;
end.
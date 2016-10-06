var t,x,y,z,hasil:longint;
	lokasi:array[1..20] of longint;
	
procedure quick(terkiri,terkanan:longint);
	var kiri,kanan,temp,pivot:longint;
	
	begin
		if terkiri < terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=lokasi[(kiri+kanan) div 2];
			
			while kiri <= kanan do
			begin
				while lokasi[kiri] < pivot do inc(kiri);
				while lokasi[kanan] > pivot do dec(kanan);
				
				if kiri <= kanan then
				begin
					temp:=lokasi[kiri];
					lokasi[kiri]:=lokasi[kanan];
					lokasi[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			quick(terkiri,kanan);
			quick(kiri,terkanan);
		end;
	end;
	
begin
	readln(t);
	for x:=1 to t do
	begin
		readln(y);
		for z:=1 to y-1 do read(lokasi[z]);
		readln(lokasi[y]);
		quick(1,y);
		hasil:=0;
		for z:=1 to y-1 do hasil:=hasil+(lokasi[z+1]-lokasi[z]);
		hasil:=2*hasil;
		writeln(hasil);
	end;
end.
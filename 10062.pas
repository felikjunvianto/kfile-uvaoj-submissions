type kasus=record
	 bil,count:longint;
	 end;

var masuk:array[1..1000] of ansistring;
	data:array[32..128] of kasus;
	bersih:array[1..96] of kasus;
	x,y,n,z:longint;
	
procedure sortprior(terkiri,terkanan:longint);
	var kiri,kanan,pivot:longint;
		temp:kasus;
		
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=bersih[(kiri+kanan) div 2].bil;
			
			while kiri<=kanan do
			begin
				while bersih[kiri].bil>pivot do inc(kiri);
				while bersih[kanan].bil<pivot do dec(kanan);
				
				if kiri<=kanan then
				begin
					temp:=bersih[kiri];
					bersih[kiri]:=bersih[kanan];
					bersih[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			
			sortprior(terkiri,kanan);
			sortprior(kiri,terkanan);
		end;
	end;	
	
procedure sort(terkiri,terkanan:longint);
	var kiri,kanan,pivot:longint;
		temp:kasus;
		
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=data[(kiri+kanan) div 2].count;
			
			while kiri<=kanan do
			begin
				while data[kiri].count<pivot do inc(kiri);
				while data[kanan].count>pivot do dec(kanan);
				
				if kiri<=kanan then
				begin
					temp:=data[kiri];
					data[kiri]:=data[kanan];
					data[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			
			sort(terkiri,kanan);
			sort(kiri,terkanan);
		end;
	end;
	
procedure ceksama(awal,akhir:longint);
	var x:longint;
		
	begin
		dec(awal);
		repeat
			inc(awal);
			x:=awal+1;
			while ((bersih[x].count=bersih[awal].count)and (x<=akhir)) do inc(x);
			dec(x);
			sortprior(awal,x);
			awal:=x;
		until awal>=akhir;
	end;
		
begin
	n:=0;
	while not(eof) do
	begin
		inc(n);
		readln(masuk[n]);
	end;
	
	for z:=1 to n do
	begin
		for x:=32 to 128 do 
		begin
			data[x].bil:=x;
			data[x].count:=0;
		end;
		for x:=1 to length(masuk[z]) do inc(data[(ord(masuk[z,x]))].count);
		sort(32,128);
		y:=0;
		for x:=32 to 128 do if data[x].count>0 then
		begin
			inc(y);
			bersih[y]:=data[x];
		end;
		ceksama(1,y);
		for x:=1 to y do writeln(bersih[x].bil,' ',bersih[x].count);
		if z<n then writeln;
	end;
end.
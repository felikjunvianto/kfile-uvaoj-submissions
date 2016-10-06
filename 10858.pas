var n,x,count:longint;
	factor:array[1..25] of longint;
	cetak:array[1..2000] of string;
	
procedure list(num,next:longint);
	var y,z:longint;
		carry:array[1..25] of longint;
		temp:string;
		kecil:boolean;
		
	begin
		for y:=2 to trunc(sqrt(num)) do if(num mod y = 0) then
		begin
			factor[next]:=y;
			factor[next+1]:=num div y;
			carry:=factor;
			list(factor[next+1],next+1);
			
			kecil:=TRUE;
			for z:=2 to next+1 do if carry[z]<carry[z-1] then
			begin
				kecil:=FALSE;
				break;
			end;
			
			if kecil then
			begin
				inc(count);
				cetak[count]:='';
				for z:=1 to next+1 do
				begin
					str(carry[z],temp);
					cetak[count]:=cetak[count]+temp;
					if z<=next then cetak[count]:=cetak[count]+' ';
				end;
			end;
		end;
	end;
	
begin
	repeat
		readln(n);
		if n>0 then
		begin
			count:=0;
			fillchar(factor,sizeof(factor),n);
			list(n,1);
			writeln(count);
			for x:=1 to count do writeln(cetak[x]);
		end;
	until n=0;
end.
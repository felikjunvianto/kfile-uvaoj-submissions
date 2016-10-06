var x,y,z,carry,sisa:longint;
	temp:string;
	bil1,bil2:array[1..10] of integer;
	
begin
	repeat
		readln(temp);
		if temp<>'0 0' then
		begin
			fillchar(bil1,sizeof(bil1),0);
			fillchar(bil2,sizeof(bil2),0);
			z:=pos(' ',temp);
			for x:=1 to z-1 do val(copy(temp,1,z-1)[z-x],bil1[x],y);
			for x:=1 to length(temp)-z do val(copy(temp,z+1,length(temp)-z)[length(temp)-z-x+1],bil2[x],y);
			
			carry:=0;
			sisa:=0;
			for x:=1 to 10 do
			begin
				bil1[x]:=bil1[x]+bil2[x]+sisa;
				if bil1[x]>9 then
				begin
					inc(carry);
					sisa:=bil1[x] div 10;
					bil1[x]:=bil1[x] mod 10;
				end else sisa:=0;
			end;
			
			if carry=0 then write('No') else write(carry);
			write(' carry operation');
			if ((carry=0)or(carry=1)) then writeln('.') else writeln('s.');
		end;
	until temp='0 0';
end.
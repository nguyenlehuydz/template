for(int i=0;i<n;i++) for(int mask = 0; mask < (1<<n);mask++)
	if (BIT(mask,i)==0) s[mask|(1<<i)]+=s[mask];
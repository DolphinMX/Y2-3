load spot_num.txt
ssn=spot_num(:,4);
ssn=ssn-mean(ssn);
[freq_resp, freq_index]=freqz(ssn,1,50000,1);
plot(freq_index, abs(freq_resp))
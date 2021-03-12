int set = (1 << 10) - 1;
for (int subset = set; subset; subset = ((subset - 1) & set)) {
}
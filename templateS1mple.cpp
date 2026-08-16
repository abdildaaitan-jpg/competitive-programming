// vector < int > tt;
// vector < int > df;
// void build(int tn, int ts, int te) {
//     if (ts == te) {
//         tt[tn] = df[ts];
//         return;
//     }
//     int mid = (ts + te) / 2;
//     build(tn << 1, ts, mid);
//     build(tn << 1 | 1, mid + 1, te);
//     tt[tn] = tt[tn << 1] + tt[tn << 1 | 1];
// }
// void upd(int tn, int ts, int te, int id, int val) {
//     if (ts == te) {
//         tt[tn] = val;
//         return;
//     }
//     int mid = (ts + te) >> 1;
//     if (id <= mid) upd(tn << 1, ts, mid, id, val);
//     else upd(tn << 1 | 1, mid + 1, te, id, val);
//     tt[tn] = tt[tn << 1] + tt[tn << 1 | 1];
// }
// int get(int tn, int ts, int te, int l, int r) {
//     if (r < ts || l > te) return 0;
//     if (l <= ts && r >= te) return tt[tn];
//     int mid = (ts + te) >> 1;
//     return get(tn << 1, ts, mid, l, r) + get(tn << 1 | 1, mid + 1, te, l, r);
// }
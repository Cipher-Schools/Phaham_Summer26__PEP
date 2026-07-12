// lc - 1732

int largestAltitude(vector<int>& gain) {
    int altitude = 0, maxAlt = 0;  // starts at 0 altitude
    for (int g : gain) {
        altitude += g;             // running prefix sum of gains
        maxAlt = max(maxAlt, altitude);
    }
    return maxAlt;
}
// gain=[-5,1,5,0,-7]: altitudes = 0→-5→-4→1→1→-6
// maxAlt tracks: 0, 0, 0, 1, 1, 1 → answer = 1
// Time O(n), Space O(1) — no array needed, just two variables
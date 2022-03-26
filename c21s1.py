# Problem: Crazy Fencing

# Get fence input:
fences = int(input())
fenceHeights = input().split()
fenceWidths = input().split()

# Convert to integers:
fenceHeights = [int(fenceHeight) for fenceHeight in fenceHeights]
fenceWidths = [int(fenceWidth) for fenceWidth in fenceWidths]
fenceAreas = []

for n in range(0, fences):

    # Get rectangle and triangle areas for every fence:
    nRect = fenceWidths[n] * min(fenceHeights[n], fenceHeights[n+1])
    nTri = fenceWidths[n] * abs(fenceHeights[n] - fenceHeights[n+1]) / 2
    fenceAreas.append(nRect + nTri)

print(sum(fenceAreas))

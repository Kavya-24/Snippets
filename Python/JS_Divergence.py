from math import log2

def kl_divergence(p, q):
	kl_divergence = 0
	for i in range(min(len(p),len(q))):
		kl_divergence += p[i] * log2(p[i]/q[i])
	return kl_divergence


def js_divergence(p, q):
  p = [float(x) for x in p]
  q = [float(x) for x in q]
  m = []
  for i in range(min(len(p),len(q))):
    m.append((p[i]+q[i])/2)
  return 0.5 * kl_divergence(p, m) + 0.5 * kl_divergence(q, m)

p = [0.5, 0.3, 0.1, 0.1]
q = [0.2, 0.3, 0.2, 0.3]

jsd = js_divergence(p, q)
print(jsd)

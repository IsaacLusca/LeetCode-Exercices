function criticalConnections(n: number, connections: number[][]): number[][] {
    const graph: number[][] = Array.from({ length: n }, () => []);
    // Identificador único para cada nó
    const ids: number[] = new Array(n).fill(-1); 
    // Menor id alcançável

    
    const low: number[] = new Array(n).fill(0); 
    const visited: boolean[] = new Array(n).fill(false);
    const result: number[][] = [];
    let time = 0;

    // Construir o grafo
    for (const [u, v] of connections) {
        graph[u].push(v);
        graph[v].push(u);
    }

    const dfs = (node: number, parent: number) => {
        visited[node] = true;
        ids[node] = low[node] = time++;
        
        for (const neighbor of graph[node]) {
            // Ignorar a aresta de onde viemos
            if (neighbor === parent) continue; 
            if (!visited[neighbor]) {
                dfs(neighbor, node);
                low[node] = Math.min(low[node], low[neighbor]);
                if (low[neighbor] > ids[node]) {
                    result.push([node, neighbor]);
                }
            } else {
                low[node] = Math.min(low[node], ids[neighbor]);
            }
        }
    };

    // Iniciar a busca em profundidade
    for (let i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, -1);
    }

    return result;
}

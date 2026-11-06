function Tower(n, src, aux, des) {
    
    if (n > 0) {  //todo:  Base case
        // Step 1: move n-1 disks from src → aux
        Tower(n - 1, src, des, aux);
    
        // Step 2: move nth disk from src → des
        console.log(`Move Disk ${n} from ${src} to ${des}`);
    
        // Step 3: move n-1 disks from aux → des
        Tower(n - 1, aux, src, des);
    }
    
}


const n = 3;
Tower(n, 'A', 'B', 'C');

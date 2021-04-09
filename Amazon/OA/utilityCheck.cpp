int auto_scale(std::vector<int> average_utils, int num_instances) {
    // WRITE YOUR BRILLIANT CODE HERE
    int instance = num_instances;
    for (int i = 0; i < average_utils.size(); i++) {
        int util = average_utils[i];
        if (util > 60) {
            if (instance <= 1e8) {
                instance *= 2;
                i += 10;
            }
        } else if (util < 25) {
            if (instance > 1) {
                instance = ceil((double)instance / 2.0);
                i += 10;
            }
        }
    }   
    return instance;
}

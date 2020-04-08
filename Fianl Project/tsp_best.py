import numpy as np
import argparse
import math
import random
import time


def parse_args():
    parser = argparse.ArgumentParser(description='TSP')
    parser.add_argument('--test_file_dir', help='the dir to test file')
    args = parser.parse_args()
    return args


class TSPSOL():
    """
    Reference:
    [1] Zhan, Shi-hua, et al. "List-based simulated annealing algorithm for traveling salesman problem." Computational intelligence and neuroscience 2016 (2016).
    """
    def __init__(self, test_file_dir):
        self.tsp_start = time.time()
        self.test_file_dir = test_file_dir
        self.dist_matrix = self.get_dist_matrix()
        self.num_cities = len(self.dist_matrix)
        self.base_sol_paths, self.base_sol_dists, used_time = self.nearestNeighbourSolution()
        self.best_sol_paths, self.best_sol_dists = self.base_sol_paths, self.base_sol_dists
        self.min_dists = self.best_sol_dists
        self.sol_dists_list = [self.base_sol_dists]

        self.max_iterations = 100000
        self.temp = 100000
        self.stopping_temp = 1e-10
        self.alpha = 1 -  5e-5
        self.iteration = 1
        print("Init path sum = {:f}, used time = {:.2f}, travels {} cities, will itearate {:d} times".format(self.base_sol_dists, used_time, self.num_cities, self.max_iterations))

    def get_dist_matrix(self):
        cities = self.get_cities()
        return self.get_dist(cities)

    def get_dist(self, cities):
        return np.round(np.sqrt((np.square(cities[:, np.newaxis] - cities).sum(axis=2))))

    def get_cities(self):
        cities = []
        with open(self.test_file_dir, 'r') as f:
            lines = f.readlines()
            for line in lines:
                oneline = line.replace("\n", "")
                oneline = oneline.strip()
                tmp = oneline.split(" ")
                while "" in tmp:
                    tmp.remove("")
                if len(tmp) != 3:
                    continue
                cid, x, y = tmp
                cities.append([float(x), float(y)])
        return np.array(cities)

    def nearestNeighbourSolution(self):
        start = time.time()
        node = random.randrange(self.num_cities)
        first_node = node
        result = [node]

        # nodes_to_visit = list(range(self.num_cities))
        nodes_to_visit = list(range(len(self.dist_matrix)))
        nodes_to_visit.remove(node)

        dist = 0
        while nodes_to_visit:
            # print(node, nodes_to_visit)
            # print(self.dist_matrix.shape)
            nearest_node = min([(self.dist_matrix[node][j], j) for j in nodes_to_visit], key=lambda x: x[0])
            dist += self.dist_matrix[node][nearest_node[1]]
            node = nearest_node[1]
            nodes_to_visit.remove(node)
            result.append(node)
        dist += self.dist_matrix[node][first_node]
        assert len(result) == self.num_cities
        end = time.time()
        used_time = end - start
        return result, dist, used_time

    def simulated_anneal(self):
        '''
        simulated annealling,  details see the reference paper.
        '''
        while self.temp >= self.stopping_temp and self.iteration < self.max_iterations:

            candidate = list(self.base_sol_paths)
            l = random.randint(2, self.num_cities - 1)
            i = random.randint(0, self.num_cities - l)

            candidate[i: (i + l)] = reversed(candidate[i: (i + l)])
            candidate_paths_dists = self.calculate_path(candidate)

            if candidate_paths_dists < self.best_sol_dists:
                self.best_sol_dists = candidate_paths_dists
                self.best_sol_paths = candidate
                if self.best_sol_dists < self.min_dists:
                    self.min_dists = self.best_sol_dists
                    self.min_paths = self.best_sol_paths
                    print("Finished {:6d}th iteration, get new path dist = {}".format(self.iteration, self.min_dists))
            else:
                if random.random() < self.acceptance_probability(candidate_paths_dists):
                    self.best_sol_dists = candidate_paths_dists
                    self.best_sol_paths = candidate
            #update
            self.temp *= self.alpha
            self.iteration += 1
            if self.iteration % 1000 == 0 and self.iteration != 0:
                check_time = time.time()
                if check_time - self.tsp_start > 4.5 * 60:
                    print("RUN OUT OF TIME ({}s<5min)".format(check_time - self.tsp_start))
                    break
        print("totally iterate: {}/{}".format(self.iteration, self.max_iterations))

    def acceptance_probability(self, candidate_paths_dists):
        return math.exp(-abs(candidate_paths_dists - self.best_sol_dists) / self.temp)

    def calculate_path(self,  path_list):
        '''
        Calcuate dist alone the path
        '''
        return sum([self.dist_matrix[i, j] for i, j in zip(path_list, path_list[1:] + [path_list[0]])])

    def write_to_file(self):
        output_file_dir = self.test_file_dir + ".tour"
        with open(output_file_dir, 'w') as f:
            f.write("{}\n".format(int(self.min_dists)))
            for ids in self.min_paths:
                f.write("{}\n".format(int(ids)))
            print("Test file {} is solved, the result is written to {}".format(self.test_file_dir, output_file_dir))


def main(test_file_dir):
    tsp_solver = TSPSOL(test_file_dir)
    tsp_solver.simulated_anneal()
    tsp_solver.write_to_file()
    end_time = time.time()
    total_time = end_time - tsp_solver.tsp_start
    print("Total time used is {}".format(total_time))


if __name__ == '__main__':
    """
    Usage:      python3 tsp_best.py --test_file_dir=test_case/test-input-().txt
    validate:   python3 TSP_Files/tsp-verifier.py test_case/test-input-().txt test_case/test-input-().txt.tour
    """
    args = parse_args()
    main(args.test_file_dir)

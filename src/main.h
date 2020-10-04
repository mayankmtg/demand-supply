#include <vector>
#include <fstream>
#include <iostream>

#include "transaction.h"
#include "order.h"
#include "string_utils.h"
#include "domain.h"

std::vector<order> supply;
std::vector<order> demand;
std::vector<Transaction> transactions;
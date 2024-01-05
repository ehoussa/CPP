#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<Data> &vtdate) {
    ft_sortv(vtdate);
}

PmergeMe::PmergeMe(std::deque<Data> &dqdate) {
    ft_sortd(dqdate);
}

void PmergeMe::ft_sortv(std::vector<Data> &vtdate)
{
    if (vtdate.size() <= 2) {
        if (vtdate.size() == 2 && vtdate[0].value > vtdate[1].value) {
            std::swap(vtdate[0].value, vtdate[1].value);
            std::swap(vtdate[0].valuesVector, vtdate[1].valuesVector);
        }
        this->sorted.push_back(vtdate[0]);
        if (vtdate.size() == 2)
            this->sorted.push_back(vtdate[1]);
        return;
    }
    std::vector<std::pair<Data, Data> > forpr;
    std::vector<std::pair<Data, Data> >::iterator itp;
    std::vector<Data>::iterator it;
    std::pair <Data, Data> p;
    Data stragler;
    bool    checkstra = false;
    int idroom = 0;

    for (it = vtdate.begin(); it != vtdate.end(); ++it) {
        p.first = *it;
        if (++it == vtdate.end()) {
            stragler.value = p.first.value;
            stragler.valuesVector = p.first.valuesVector;
            checkstra = true;
            break;
        }
        p.second = *it;
        if (p.first.value < p.second.value) {
            std::swap(p.first.value, p.second.value);
            std::swap(p.first.valuesVector, p.second.valuesVector);
        }
        p.first.valuesVector.push_back(idroom);
        p.second.valuesVector.push_back(idroom);
        ++idroom;
        forpr.push_back(p);
    }
    vtdate.clear();
    for (itp = forpr.begin(); itp != forpr.end(); ++itp) {
        vtdate.push_back(itp->first);
    }
    ft_sortv(vtdate);
    vtdate.clear();
    for (it = this->sorted.begin(); it != this->sorted.end(); ++it) {
        vtdate.push_back(forpr[it->valuesVector.back()].second);
        it->valuesVector.pop_back();
        vtdate.back().valuesVector.pop_back();
    }
    this->sorted.insert(this->sorted.begin(), vtdate[0]);
    int ind = 1;
    std::vector<Data>::iterator iter;
    for (it = vtdate.begin() + 1; it != vtdate.end(); ++it) {
        iter = std::lower_bound(sorted.begin(), sorted.begin() + 2 * ind++, *it);
        this->sorted.insert(iter, *it);
    }
    if (checkstra) {
        iter = std::lower_bound(sorted.begin(), sorted.end(), stragler);
        sorted.insert(iter, stragler);
    }
}

void PmergeMe::ft_sortd(std::deque<Data> &dqdate)
{
    if (dqdate.size() <= 2) {
        if (dqdate.size() == 2 && dqdate[0].value > dqdate[1].value) {
            std::swap(dqdate[0].value, dqdate[1].value);
            std::swap(dqdate[0].valuesVector, dqdate[1].valuesVector);
        }
        this->sorted2.push_back(dqdate[0]);
        if (dqdate.size() == 2)
            this->sorted2.push_back(dqdate[1]);
        return;
    }
    std::deque<std::pair<Data, Data> > forpr;
    std::deque<std::pair<Data, Data> >::iterator itp;
    std::deque<Data>::iterator it;
    std::pair <Data, Data> p;
    Data stragler;
    bool    checkstra = false;
    int idroom = 0;

    for (it = dqdate.begin(); it != dqdate.end(); ++it) {
        p.first = *it;
        if (++it == dqdate.end()) {
            stragler.value = p.first.value;
            stragler.valuesVector = p.first.valuesVector;
            checkstra = true;
            break;
        }
        p.second = *it;
        if (p.first.value < p.second.value) {
            std::swap(p.first.value, p.second.value);
            std::swap(p.first.valuesVector, p.second.valuesVector);
        }
        p.first.valuesVector.push_back(idroom);
        p.second.valuesVector.push_back(idroom);
        ++idroom;
        forpr.push_back(p);
    }
    dqdate.clear();
    for (itp = forpr.begin(); itp != forpr.end(); ++itp) {
        dqdate.push_back(itp->first);
    }
    ft_sortd(dqdate);
    dqdate.clear();
    for (it = this->sorted2.begin(); it != this->sorted2.end(); ++it) {
        dqdate.push_back(forpr[it->valuesVector.back()].second);
        it->valuesVector.pop_back();
        dqdate.back().valuesVector.pop_back();
    }
    this->sorted2.insert(this->sorted2.begin(), dqdate[0]);
    int ind = 1;
    std::deque<Data>::iterator iter;
    for (it = dqdate.begin() + 1; it != dqdate.end(); ++it) {
        iter = std::lower_bound(sorted2.begin(), sorted2.begin() + 2 * ind++, *it);
        this->sorted2.insert(iter, *it);
    }
    if (checkstra) {
        iter = std::lower_bound(sorted2.begin(), sorted2.end(), stragler);
        sorted2.insert(iter, stragler);
    }
}

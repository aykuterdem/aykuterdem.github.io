function [ycap accuracy niter] = gtg(y,W,labeled,plabs)

% Function [ycap accuracy niter] = gtg(y,W,labeled,plabs) 
% Semi-Supervised Learning using Multi-population Replicator Dynamics
% using payoff matrix in terms of normalized similarity matrix S=D^-1/2WD^-1/2
% 
% Graph Transduction as a Non-Cooperative Game, Aykut Erdem and Marcello Pelillo, 
% Neural Computation, Vol. 24, No. 3, pp. 700-723, March 2012
% 
% Inputs:    y - ground truth 
%            W - similarity matrix 
%            labeled - inlabeled point indices
%            plabs - provided labels 
%
% Outputs:   ycap - estimated labeld
%            error - test error
%            niter - total number of iterations
%
% Please note that there is no warranty.
% Aykut Erdem, aykut@cs.hacettepe.edu.tr
% 2012

nPts = size(W,1);
nCluster = size(plabs,2);

W = W-diag(diag(W));
D12 = diag(sum(W,2).^-0.5);
S = D12*W*D12;

p = ones(nPts,nCluster)/nCluster;
p(labeled,:) = plabs;

niter = 0;
pnew = zeros(nPts,nCluster);
C = 0;
while true,
    q = S*p;
    C=max(-min(q(:))+1e-20,C); % In case of negative similarities
    dummy = p.*(q+C);
    for k=1:nCluster
        pnew(:,k) = dummy(:,k)./sum(dummy,2);
    end
 
    diff = norm(p(:)-pnew(:));
    p = pnew;
    niter = niter+1;
    if diff<10^-4 | niter==10^4
       break;
    end
end

unlabeled = setdiff(1:nPts,labeled);
nU = length(unlabeled);

correct = 0;
ycap = zeros(nU,1);
for i=1:nU
    [dummyy ycap(i)] = max(pnew(unlabeled(i),:));
    if ycap(i)==y(unlabeled(i))
       correct=correct+1;
    end
end

accuracy = correct/nU;

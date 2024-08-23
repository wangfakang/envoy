FROM node:22.7-bullseye-slim@sha256:6bdd5766dc26c92f47cddf61eaa330170d9a9bfb65829e07d2f71ac84db01469 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
